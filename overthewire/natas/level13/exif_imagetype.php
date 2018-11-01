<?

if (exif_imagetype('./exploit.php')) {
  print "exploit.php appears to be an image\n";
}
else {
  print "exploit.php does NOT pass the image test\n";
}
