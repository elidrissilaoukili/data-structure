<?php
// Example 1
$pizza  = "piece1 piece2 piece3 piece4 piece5 piece6";
$pieces = explode(" ", $pizza);

for ($i=0; $i < count($pieces) ; $i++) { 
    echo $pieces[$i] . " - ";
}

echo "<br><pre>";
print_r($pieces);


?>