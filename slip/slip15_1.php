<?php
    $s=$_POST['t1'];
    $c=$_POST['c'];
    switch ($c) {
        case 1:
            $ar = explode(' ', $s);
            echo "First five words of string:<br>";
            for ($i = 0; $i < min(5, count($ar)); $i++) {
                echo "$ar[$i]<br>";
            }
            break;
        case 2:
            $lower = strtolower($s);
            echo "String in lowercase: $lower<br>";
            $title = ucwords($s);
            echo "String in title case: $title";
            break;
        case 3:
            $padded = str_pad($s, 60, "*", STR_PAD_BOTH);
            echo "Padded string: $padded";
            break;
        case 4:
            $trimmed = trim($s);
            echo "Trimmed string: $trimmed";
            break;
        case 5:
            $rev = strrev($s);
            echo "Reverse of String: $rev";
            break;
        default:
            echo "Invalid choice";
            break;
    }
?>