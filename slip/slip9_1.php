<?php
$str = $_POST['string'];
$separator = $_POST['select'];
echo "<BR> String is : $str";
echo "<BR> Selector is : $separator <BR>";
echo "<BR> Split the string into separate words using the given separator :<BR>";
$ans = explode($separator,$str);
foreach ($ans as $words )
{
echo $words;
echo "<BR>";
}
echo "<BR>Replace all the occurrences of separator in the given string with some other
separator:<BR>";
echo str_replace(',', '@', $str);
echo "<BR> Find the last word in the given string(Use strrstr() function): <BR>";
echo strstr($str, $separator,false);
?>