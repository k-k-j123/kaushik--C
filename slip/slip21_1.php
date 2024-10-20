<?php
$temp_array = array(78, 60, 62, 68, 71, 68, 73, 85, 66, 64, 76, 63, 81, 76, 73);
$tot_temp = 0;
$temp_array_length = count($temp_array);
foreach($temp_array as $temp)
{
$tot_temp += $temp;
}
$avg_high_temp = $tot_temp/$temp_array_length;
echo "Average Temperature is : $avg_high_temp";
sort($temp_array);
echo " List of five lowest temperatures :";
for ($i=0; $i< 5; $i++)
{
echo $temp_array[$i].", ";
}
echo "List of five highest temperatures :";
rsort($temp_array);
for($i=0;$i<5;$i++)
{
echo $temp_array[$i].",";
}
?>