# Camera to ROS transform

# Overview
Exchange coordinates from pco-flexx coordinate (camera coordinate) to ROS coordinate.

# Coorespondence table
|pico-flexx|ROS|
|-------|-------|
|$x$|$z$|
|$y$|$x$|
|$z$|$y$|

# Inputs / Outputs / API
## Input
|Name|Type|Description|
|-------|-------|-------|
|`input`|`sensor_msgs::PointCloud2`|Input Point Cloud.|


## Output
|Name|Type|Description|
|-------|-------|-------|
|`output`|`sensor_msgs::PointCloud2`|Output Point Cloud.|

# Parameter
|Name|Description|
|-------|-------|
|`output_tf`|TF name of output point cloud.|
