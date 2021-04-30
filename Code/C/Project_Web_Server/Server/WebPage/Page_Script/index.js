var CurrentPassword = "Ubuntu";
var CurrentUsername = "Admin";

function Login(){
    if(document.getElementById('Username').value == CurrentUsername){
        if (document.getElementById('Password').value == CurrentPassword){
            console.log("Wello " + CurrentUsername);
            document.getElementById("Login_status").innerHTML = "Logged in";
        }
    }
};