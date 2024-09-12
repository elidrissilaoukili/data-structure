<?php

$text = 'https://elidrissilaoukili.netlify.app/me.png';

$pattern = "/\.netlify\.app/";
$replacement = ".com";

echo $text;
echo "<br>";
echo preg_replace($pattern, $replacement, $text);
