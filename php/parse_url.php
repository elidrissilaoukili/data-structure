<?php
$url = "https://www.php.net/?name=mohammed&lastName=laoukili";


function getTable($url){
    $queryString = parse_url($url, PHP_URL_QUERY);
    $change_to_arr_assoc = parse_str($queryString, $arr_assoc);

    $keys = array_keys($arr_assoc);
    $values = array_values($arr_assoc);

    $table2 = [
        $keys,
        $values
    ];

    return $table2;
}

$table = getTable($url);
echo "<pre>";
print_r($table);



?>