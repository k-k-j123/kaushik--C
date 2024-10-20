<?php
    $operation = $_POST['operation'];
    $chunkSize = $_POST['chunk_size'];

    $array = array(2,3,4,1,3,5,6);
    if ($operation == "split") {
        $chunks = array_chunk($array, $chunkSize);
        echo "Array chunks:\n";
        print_r($chunks);
    } elseif ($operation == "sort") {
        sort($array);
        echo "Sorted array:\n";
        print_r($array);
    } elseif ($operation == "filter") {
        $evenElements = array_filter($array, function($value) {
            return $value % 2 == 0;
        });
        echo "Even elements:\n";
        print_r($evenElements);
    }
?>