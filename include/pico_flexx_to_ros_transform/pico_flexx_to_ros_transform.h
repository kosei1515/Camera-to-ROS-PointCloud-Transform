#pragma once
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include <nodelet/nodelet.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pluginlib/class_list_macros.h>

namespace pico_flexx_to_ros_transform {
class PicoFlexxtoROSTransform : public nodelet::Nodelet {
private:
  ros::NodeHandle nh_, pnh_;
  ros::Subscriber sub_pc_;

  ros::Publisher pub_pc_;

  // object
  pcl::PointCloud<pcl::PointXYZ> pc_in_;

  pcl::PointCloud<pcl::PointXYZ> pc_out_;

  std::string output_tf_;

public:
  PicoFlexxtoROSTransform();
  ~PicoFlexxtoROSTransform();

  virtual void onInit();

  void pc_callback(const sensor_msgs::PointCloud2ConstPtr &pc_msg);
};

} // namespace pointcloud_preprocessor
