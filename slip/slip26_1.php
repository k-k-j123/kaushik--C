<?php

$host = "localhost";
$dbname = "your_database_name";
$username = "your_username";
$password = "your_password";


$conn = pg_connect("host=$host dbname=$dbname user=$username password=$password");


if (!$conn) {
  echo "Connection failed.";
  exit;
}

$hname = $_POST['hname'];

$sql = "SELECT d.doc_no, d.dname, d.address, d.city, d.area 
        FROM Doctor d 
        JOIN Doctor_Hospital dh ON d.doc_no = dh.doc_no 
        JOIN Hospital h ON dh.hosp_no = h.hosp_no 
        WHERE h.hname = $hname";

$result = pg_query($conn, $sql);


echo "<table border='1'>";
echo "<tr><th>Doc No</th><th>Doctor Name</th><th>Address</th><th>City</th><th>Area</th></tr>";

if (pg_num_rows($result) > 0) {
  while($row = pg_fetch_array($result)) {
    echo "<tr><td>" . $row["doc_no"]. "</td><td>" . $row["dname"]. "</td><td>" . $row["address"]. "</td><td>" . $row["city"]. "</td><td>" . $row["area"]. "</td></tr>";
  }
} else {
  echo "0 results";
}
echo "</table>";

pg_close($conn);

?>