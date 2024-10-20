<?php
    $f1=$_POST['f1'];
    $f2=$_POST['f2'];
    if (!file_exists($f1)) {
        echo "Error: $f1 does not exist.";
        exit;
    }
    if (!file_exists($f2)) {
        echo "Error: $f2 does not exist.";
        exit;
    }
    $content=file_get_contents($f1);
    file_put_contents($f2,$content, FILE_APPEND);
    echo "Content of $f1 appended to $f2 successfully.";
?>