<?php
  $param = "./.list/";
  $param = $argv[1];
  $param = str_replace( array("../", "..\\"), "", $param);
  echo "/var/www/html/" . $param;
  echo "\n";
?>
