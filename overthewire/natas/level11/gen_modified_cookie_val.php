<?

$defaultdata = array( "showpassword"=>"yes", "bgcolor"=>"#ffffff");

function xor_encrypt($in) {
  $key = 'qw8J';
  $text = $in;
  $outText = '';

  // Iterate through each character
  for ($i=0; $i < strlen($text); $i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
  }

  return $outText;
}

function loadData($def) {
  $mydata = $def;
  return $mydata;
}

function saveData($d) {
  $json_d = json_encode($d);
  print("saveData(): json_encode(d) $json_d\n");
  $cookie = base64_encode(xor_encrypt(json_encode($d)));
  print "saveData(): $cookie\n";
}

$data = loadData($defaultdata);
saveData($data);

?>
