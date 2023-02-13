#include <pico_flexx_to_ros_transform/pico_flexx_to_ros_transform.h>

namespace pico_flexx_to_ros_transform {
PicoFlexxtoROSTransform::PicoFlexxtoROSTransform() : nh_(), pnh_() {}

PicoFlexxtoROSTransform::~PicoFlexxtoROSTransform() {}

void PicoFlexxtoROSTransform::onInit() {
  NODELET_INFO("picoflexx to ros Init");
  nh_ = getNodeHandle();
  pnh_ = getPrivateNodeHandle();

  pub_pc_ = nh_.advertise<sensor_msgs::PointCloud2>(
      "output", 1);

  sub_pc_ = nh_.subscribe("input", 1,
                           &PicoFlexxtoROSTransform::pc_callback, this);

  pnh_.param<std::string>("output_tf", output_tf_, "/picoflexx_ros_tf");
}

void PicoFlexxtoROSTransform::pc_callback(
    const sensor_msgs::PointCloud2ConstPtr &pc_msg) {
  pcl::PointCloud<pcl::PointXYZ>::Ptr pc_ptr(
      new pcl::PointCloud<pcl::PointXYZ>(pc_in_));
  pcl::PointCloud<pcl::PointXYZ>::Ptr pc_out_ptr(
      new pcl::PointCloud<pcl::PointXYZ>(pc_out_));

  pcl::fromROSMsg(*pc_msg, *pc_ptr);

  pc_out_ptr->header.frame_id = output_tf_;
  pc_out_ptr->header.stamp = pc_ptr->header.stamp;
  pc_out_ptr->points.resize(pc_ptr->points.size());

  for (size_t i = 0; i < pc_ptr->points.size(); i++) {
    pc_out_ptr->points[i].x = pc_ptr->points[i].z;
    pc_out_ptr->points[i].y = pc_ptr->points[i].x;
    pc_out_ptr->points[i].z = pc_ptr->points[i].y;
  }

  pub_pc_.publish(*pc_out_ptr);
}
} // namespace pico_flexx_to_ros_transform
PLUGINLIB_EXPORT_CLASS(pico_flexx_to_ros_transform::PicoFlexxtoROSTransform,
                       nodelet::Nodelet);
