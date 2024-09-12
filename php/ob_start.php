<?php 

ob_start();
$nom = empty($_GET["N"]) ? "DBaS" : "Tous le monde";

?>

<html>
    <body>
        Bojour <?= $nom ?>
    </body>
</html>