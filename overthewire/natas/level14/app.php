<?

$REQUEST_username = "test_username";
$REQUEST_password = "test_password";

$query = "SELECT * from users where username=\"".$REQUEST_username."\" and password=\"".$REQUEST_password."\"";

echo "Executing query: $query\n";
?>
