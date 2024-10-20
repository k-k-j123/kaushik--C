<?php
    // Get user input
    $name = $_POST['name'];
    $age = $_POST['age'];
    $city = $_POST['city'];
    $operation = $_POST['operation'];

    // Create associative array
    $array = array(
        "name" => $name,
        "age" => $age,
        "city" => $city
    );

    switch($operation){
        case 1:
            $res=array_flip($array);
            echo "key value exchanged::<br>";
            print_r($res);
            break;
        case 2:
            $keys = array_keys($array);
            shuffle($keys);
            echo "Traversing elements in random order:\n";
            foreach ($keys as $key) {
                echo "$key => $array[$key]\n";
            }
            break;
        case 3:
            extract($array);
            echo "name=$name<br>";
            echo "age=$age<br>";
            echo "city=$city<br>";
            break;
        case 4:
            print_r($array);
    }
?>