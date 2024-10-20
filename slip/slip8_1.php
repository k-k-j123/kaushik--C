<?php
$ls = $_POST['lstring'];
$ss = $_POST['sstring'];
echo "<BR>The large string is: $ls";
echo "<BR>The small string is: $ss";
$pos = strpos($ls,$ss);
if($pos === 0)
    echo "<BR>Yes small string present at the biggining of the large string...";
else
    echo "<BR>No.. small string is not present at the biggining of the large string...";
echo "<BR> position of small string in the large string: $pos";
$compare = strncasecmp($ls, $ss, 5);
if($compare == 0)
    echo "<BR> Both string are equal";
else
    echo "<BR> strings are not equal";
?>