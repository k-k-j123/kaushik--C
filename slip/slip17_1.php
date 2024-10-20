<?php
    // Get marks from form
    $marks1 = $_POST['marks1'];
    $marks2 = $_POST['marks2'];
    $marks3 = $_POST['marks3'];
    $marks4 = $_POST['marks4'];
    $marks5 = $_POST['marks5'];

    // Calculate total and percentage
    $total = $marks1 + $marks2 + $marks3 + $marks4 + $marks5;
    $percentage = ($total / 500) * 100;

    // Determine grade
    if ($percentage >= 90) {
        $grade = 'A';
    } elseif ($percentage >= 80) {
        $grade = 'B';
    } elseif ($percentage >= 70) {
        $grade = 'C';
    } elseif ($percentage >= 60) {
        $grade = 'D';
    } else {
        $grade = 'F';
    }
?>

<table>
    <tr>
        <th>Total Marks</th>
        <th>Percentage</th>
        <th>Grade</th>
    </tr>
    <tr>
        <td><?php echo $total; ?>/500</td>
        <td><?php echo number_format($percentage, 2); ?>%</td>
        <td><?php echo $grade; ?></td>
    </tr>
</table>