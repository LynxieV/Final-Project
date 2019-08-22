var pass = "psw";
var word = "psw-repeat";

function compare_password() {
  while (true) {
    if (pass != word) {
    echo("Error... Passwords do not match");
    exit;
    break;
    }
  }
}
