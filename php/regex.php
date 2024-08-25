<?php

$text = " 
Like re generate a text with name #idricoding Mohammed El Idrissi I am a developer this my email  and this is my number +212767194500 and if you want more details check my portfolio elidrissilaoukili.netlify.app, 
for other ways to contact #github me there is this contact #google acadimic email 
767194500 0767194500.
moha@yahoo.ul
elidrissiaouki5li@gmail.com
mohammed.elidrissilaouki@usmba.ac.ma.com.hello.

mohammed123 mohammed cgdjgd
skdjfjm
com
phone number 1:  (123) 456-7890
phone number 2: 123-456-7890,
phone number 3:123.456.7890, 
phone number 4:123 456 7890.
https://www.threesl.com/blog/special-characters-regular-expressions-escape/ and elidrissilaoukili.netlify.app
random M..cd575484N1381661fsdl https://idri.netlify.app/
DD-MM-YYYY, MM/DD/YYYY, or YYYY-MM-DD
09-12-2024, 12/09/2026, or 2018-08-07 2018/08/07
09-12-24, 12/09/26, or 2018-08-07 2018/08-07 2018-08/07
ana moha 
xxx.xxx.xxx.xxx while x = [0, 255]
192.168.1.1
http://127.0.0.1:8000/
127.0.0.1:8000
127.0.0.1

<div><h1>Hello titlte</h1></div>

Paste your text here or start fresh. Duplicates are highlighted in real-time. (Once you begin, these instructions will be cleared.) text
The list of duplicates can can be found next to the editor. You can toggle highlighting for individual words by text clicking text text on them.
The toolbar offers several controls. Use the first two buttons for undoing and redoing edits. Adjust the minimum word length and minimum number of repeats using the sliders (third and fourth buttons on smaller screens). Toggle the fifth control to switch between between case-sensitive and insensitive modes. The word and character counts are displayed on the right side.
When you're ready, you can copy your your text with the button next to the top-right menu. Use the menu menu for additional options, such as selecting your preferred theme: light, dark, or system.

@elidrissi@gmail.com.sj elidrissi elidrissi
elidrissi@gmail.com
";


$find_emails = "/[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}/";
$email_valid = "/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/";
$find_phones1 = "/[0-9+]{9,}/";
$find_phones2 = "/(?:\(\d{3}\)\s?|\d{3}[-.\s])\d{3}[-.\s]\d{4}/";
$find_all_phones = "/[0-9+]{9,}|(?:\(\d{3}\)\s?|\d{3}[-.\s])\d{3}[-.\s]\d{4}/";
$url_matching = "/\bhttps?:\/\/[a-zA-Z0-9._\/:-]+\b/";
$date_extraction = "/\b(?:\d{2}[-\/]\d{2}[-\/]\d{4}|\d{4}[-\/]\d{2}[-\/]\d{2}|\d{2}[-\/]\d{2}[-\/]\d{2})\b/";

// Explanation: Ensures passwords have at least one lowercase letter, one uppercase letter, one 
// digit, one special character, and are at least 8 characters long.
$passtext = "mohammedM.q*1";
$password_validation = "/^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[&+_@?.-])[A-Za-z\d@$!%*&+_?.-]{8,}$/";
// preg_match_all($password_validation, $passtext, $matches);

$hashtags = "/#\w+/";

$ip_address = "/\b(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b/";

$html_tag_removal = "/<[^>]+>/";

$repeated_text = "my home is is near near";
$repeated_words = "/^\b(\w+)\b\s+\b\1\b$/";

$table="
<table>
	<thead>
		<tr>
			<th>name</th>
			<th>email</th>
		</tr>
	</thead>

	<tbody>
		<tr>
			<td>Mohammed</td>
			<td>mohammed@gmail.com</td>
		</tr>
		<tr>
			<td>Elidrissi</td>
			<td>elidrissi@gmail.com</td>
		</tr>
		<tr>
			<td>Laoukili</td>
			<td>laoukili@gmail.com</td>
		</tr>
	</tbody>
</table>
";
$extracting_table_data = "/<tr>\s*<td>(.*?)<\/td>\s*<td>(.*?)<\/td>\s*<\/tr>/";

preg_match_all($extracting_table_data, $table, $matches);

// Check if any matches were found
if (!empty($matches[0])) {
	echo "<pre>";
	print_r($matches);
} else {
	echo "Nothing found.\n";
}
