<?php

$filename = $_POST['filename'];
$choice = $_POST['choice'];

if (!file_exists($filename)) {
    echo "File does not exist.\n";
    exit();
}

switch ($choice) {
    case 1:
        $file_type = mime_content_type($filename);
        echo "File type: $file_type\n";
        break;
    case 2:
        $mod_time = date("Y-m-d H:i:s", filemtime($filename));
        echo "Last modification time: $mod_time\n";
        break;
    case 3:
        $file_size = filesize($filename);
        echo "File size: $file_size bytes\n";
        break;
    case 4:
        if (unlink($filename)) {
            echo "File deleted successfully.\n";
        } else {
            echo "Error deleting file.\n";
        }
        break;
    default:
        echo "Invalid choice. Please choose a valid option.\n";
}

?>