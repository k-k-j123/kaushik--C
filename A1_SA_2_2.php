<?php
	$msg=$_COOKIE['msg'];
	$style=$_COOKIE['style'];
	$size=$_COOKIE['size'];
	$fc=$_COOKIE['fcolor'];
	$bc=$_COOKIE['bcolor'];
?>
<body bgcolor='<?php echo $bc?>'>
	<font size='<?php echo $size?>' color='<?php echo $fc?>'>
	<<?php echo $style?>><?php echo $msg?></<?php echo $style?>>
</font>
</body>
