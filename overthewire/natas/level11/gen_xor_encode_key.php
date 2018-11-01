<?  
 function xor_encrypt($key, $text) {  
   $outText = '';  
   // Iterate through each character  
   for ($i=0; $i < strlen($text); $i++) {  
     $outText .= $text[$i] ^ $key[$i % strlen($key)];  
   }  
   return $outText;  
 }  

 $defaultdata = json_encode(array( "showpassword"=>"no", "bgcolor"=>"#ffffff"));
 $defaultcookie = "ClVLIh4ASCsCBE8lAxMacFMZV2hdVVotEhhUJQNVAmhSEV4sFxFeaAw";

 // obtain encrypted data
 $encrypteddata = base64_decode($defaultcookie);
 // exploit the fact that: Orig_Data XOR Encrypted_Data = KEY
 $key = xor_encrypt($defaultdata, $encrypteddata);

 print "$key\n"
?>  
