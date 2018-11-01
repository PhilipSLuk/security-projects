<?

function encodeSecret($secret) {
  return bin2hex(strrev(base64_encode($secret)));
}

function decodeSecret($input) {
  return base64_decode(strrev(hex2bin($input)));
}


$encodedSecret = "3d3d516343746d4d6d6c315669563362";
$decodedSecret = decodeSecret($encodedSecret);

print "decoded secret: $decodedSecret\n";

?>
