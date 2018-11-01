<? 

/*
 * returns a pseudo random string of 10 characters
 */
function genRandomString() {
  $characters = "0123456789abcdefghijklmnopqrstuvwxyz";
  $string = "";
  for ($p = 0; $p < 10; $p++) {
    $string .= $characters[mt_rand(0, strlen($characters)-1)];
  }
  return $string;
}

/*
 * returns a path $dir/randstr.$ext (that doesn't represent
 * an existing file
 */
function makeRandomPath($dir, $ext) {
  do {
    $path = $dir."/".genRandomString().".".$ext;
  } while(file_exists($path));
  return $path;
}

/*
 * calls makeRandomPath() to get availabe pseudo rand path name
 */
function makeRandomPathFromFilename($dir, $fn) {
  $ext = pathinfo($fn, PATHINFO_EXTENSION);
  return makeRandomPath($dir, $ext);
}

$POST_filename = "myphoto.jpg";
$target_path = makeRandomPathFromFilename("upload", $POST_filename);

print "move_uploaded_file($filename, $target_path)\n";

?>
