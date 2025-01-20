<?php
	$msg=$_POST['msg'];
	$style=$_POST['style'];
	$size=$_POST['size'];
	$fc=$_POST['fcolor'];
	$bc=$_POST['bcolor'];

	setCookie('msg',$msg);
	setCookie('style',$style);
	setCookie('size',$size);
	setCookie('fcolor',$fc);
	setCookie('bcolor',$bc);
?>
<table border=1>
	<tr>
		<td><b>Message</b></td><td><?php echo $msg?></td>
	</tr>
	<tr>
		<td><b>Style</b></td><td><?php echo $style?></td>
	</tr>
	<tr>
		<td><b>Size</b></td><td><?php echo $size?></td>
	</tr>
	<tr>
		<td><b>Foreground color</b></td><td><?php echo $fc?></td>
	</tr>
	<tr>
		<td><b>Background color</b></td><td><?php echo $bc?></td>
	</tr>
</table>
<br>
<a href='A1_SA_2_2.php'>set</a>