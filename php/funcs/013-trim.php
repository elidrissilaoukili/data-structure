<?php

$text = '<img src="https://elidrissilaoukili.netlify.app/me.png" />';

$text = trim($text, "<img src=\"");
$text = trim($text, "\" />");

echo $text;