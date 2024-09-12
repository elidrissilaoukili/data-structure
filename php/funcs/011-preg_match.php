<?php

$text = '<img src="https://elidrissilaoukili.netlify.app/me.png" />';

preg_match("/img src=\"(.*?)\.(png)\"/", $text, $match);

printf("<pre>");
print_r($match); 