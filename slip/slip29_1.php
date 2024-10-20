<?php

$host = "localhost";
$dbname = "your_database_name";
$username = "your_username";
$password = "your_password";

$conn = new mysqli($host, $username, $password, $dbname);

if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $title = $_POST['title'];

  $sql = "UPDATE Committee 
          JOIN Event_Committee ON Committee.cno = Event_Committee.cno 
          JOIN Event ON Event_Committee.eno = Event.eno 
          SET Committee.status = 'working' 
          WHERE Event.title = '$title'";

  if ($conn->query($sql) === TRUE) {
    echo "Committee status updated successfully.";
  } else {
    echo "Error updating committee status: " . $conn->error;
  }
}

$conn->close();

?>