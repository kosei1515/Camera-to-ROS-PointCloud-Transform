#include <pico_flexx_to_ros_transform/pico_flexx_to_ros_transform.h>

int main(int argc, char **argv) {
  //初期化＆ノード名をimage_rotateに設定
  ros::init(argc, argv, "pico_flexx_to_ros_transform_node");
  //オブジェクトを宣言
  pico_flexx_to_ros_transform::PicoFlexxtoROSTransform StoR;
  // Ctrl+Cが押されるまたはros::shutdown()が起こらない限りloop
  ros::spin();
  return 0;
}