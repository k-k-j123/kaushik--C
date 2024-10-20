<?php
   $sentence = $_POST['sentence'];
   $word = $_POST['word'];
   $operation = $_POST['operation'];
   $position = $_POST['position'];
   if ($operation == "delete") {
    // Delete characters using substr_replace()
    $result = substr_replace($sentence, '', $position - 1, $length);
    echo "Result after deletion:\n";
    echo "$result\n";
} elseif ($operation == "insert") {
    // Insert word using substr()
    $firstPart = substr($sentence, 0, $position - 1);
    $secondPart = substr($sentence, $position - 1);
    $result = $firstPart . $word . $secondPart;
    echo "Result after insertion:\n";
    echo "$result\n";
} elseif ($operation == "replace") {
    // Replace characters using substr_replace()
    $result = substr_replace($sentence, $word, $position - 1, $length);
    echo "Result after replacement:\n";
    echo "$result\n";
}
?>