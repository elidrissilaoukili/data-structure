<?php // elidrissilaoukili.netlify.app
// Define the directory containing the images
$directory = 'path/to/your/image/folder';

// Define the output file where names will be saved
$outputFile = 'image_names.txt';

// List of image file extensions you want to include
$imageExtensions = ['jpg', 'jpeg', 'png', 'gif', 'bmp', 'tiff'];

// Open the output file in write mode
$fileHandle = fopen($outputFile, 'w');

if ($fileHandle) {
    // Open the directory
    if ($handle = opendir($directory)) {
        // Loop through all files in the directory
        while (false !== ($filename = readdir($handle))) {
            // Skip '.' and '..'
            if ($filename == '.' || $filename == '..') {
                continue;
            }

            // Get file extension
            $extension = strtolower(pathinfo($filename, PATHINFO_EXTENSION));

            // Check if the file is an image
            if (in_array($extension, $imageExtensions)) {
                // Write the filename to the output file
                fwrite($fileHandle, $filename . PHP_EOL);
            }
        }
        closedir($handle);
    }

    // Close the output file
    fclose($fileHandle);

    echo "Image names have been saved to $outputFile";
} else {
    echo "Failed to open the output file.";
}

// Run the Script: Run the PHP script from the command line or via a web server. For command line, use:
// php list_images.php
