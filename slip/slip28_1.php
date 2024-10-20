<?php

$file = fopen('student.dat', 'r');

if ($file) {
  echo "<table border='1'>";
  echo "<tr><th>Roll No</th><th>Name</th><th>OS</th><th>WT</th><th>DS</th><th>Python</th><th>Java</th><th>CN</th><th>Percentage</th></tr>";

  while (($line = fgets($file)) !== false) {
    $data = explode('|', trim($line));
    $total = array_sum(array_slice($data, 2));
    $percentage = ($total / 6) * 100;
    echo "<tr>";
    foreach ($data as $value) {
      echo "<td>$value</td>";
    }
    echo "<td>$percentage%</td>";
    echo "</tr>";
  }
  echo "</table>";
  fclose($file);
} else {
  echo "Error opening file.";
}

?>