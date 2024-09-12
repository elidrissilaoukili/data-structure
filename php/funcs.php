<?php
$data = [
    "id" => 1,
    "first_name" => "mohammed",
    "last_name" => "el idrissi",
    "username" => "elidrissilaoukili",
    "birth" => "06/09/2001"
];

echo "<pre>";
extract($data) . "<br>";
echo $id . "<br>";
echo $first_name . "<br>";
echo $last_name . "<br>";
echo $username . "<br>";
echo $birth . "<br>";



$id = $data["id"];
unset($data["id"]);
$keys = array_keys($data);
$values = array_values($data);


$fillable = implode(', ', $keys);
$data = join(', ', array_fill(0, count($values), "?"));
$query = "INSERT INTO table_name($fillable) values ($data);";

echo "<br>";
echo $query;

if ($id) {
    $fillable = implode(' = ?, ', $keys) . " = ?";

    $query = "  
    UPDATE table_name 
    SET $fillable 
    where id = ?;
    ";
    $values[] = $id;
}

echo "<br>";
echo $query;
