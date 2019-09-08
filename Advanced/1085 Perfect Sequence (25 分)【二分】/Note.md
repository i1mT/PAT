# 



##### algorithm中的二分查找

`upper_bound(v.begin(), v.end(), val)` 在begin与end的左闭右开区间二分查找val，返回**大于val**的第一个位置。

`lower_bound(v.begin(), v.end(), val)`在begin与end的左闭右开区间二分查找val，返回**小于等于val**的第一个位置。

`binary_search(v.begin(), v.end(), val)`，返回bool，表示是否存在该数。