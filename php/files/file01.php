<?php

// $filename = "../funcs.php";

// $file = fopen($filename, 'r');

// if ($file) {
//     while (($line = fgets($file)) !== false) {
//         echo "<pre>";
//         echo $line;
//     }
//     fclose($file);
// } else {
//     echo "Unable to open the file.";
// }

$getf = __DIR__ . "/../../algorithms/x.c";
$dest = __DIR__ . "/";
$_FILES['myfile'] = $getf;
if (move_uploaded_file($_FILES['myfile'], $dest)) {
    print "Téléchargé avec succès!";
} else {
    print "Échec du téléchargement!";
}