<?php
if (isset($_POST['submit'])){
    $file = $_FILES['file'];

    $fileName = $_FILES['file']['name'];
    $fileTmpName = $_FILES['file']['tmp_name'];
    $fileSize = $_FILES['file']['size'];
    $fileError = $_FILES['file']['error'];
    $fileType = $_FILES['file']['type'];

    $fileExt = explode('.', $fileName);
    $fileActualExt =  strtolower(end($fileExt));

    $allow = array('jpg', 'jpeg', 'png', 'ico');

    if (in_array($fileExt, $allow)){
        if ($fileError === 0){
            if ($fileSize < 100000000){
                $fileNameNew = uniqid('', true).".".$fileActualExt;
                $fileDestination = 'uploads/'.$fileNameNew;

                move_uploaded_file($fileTmpName, $fileDestination);
                echo "File uploaded";

            }
            else{
                echo "Error: Your file is too BIG!"
            }
        }
        else {
            echo "Error: There was an error uploading your file!"
        }
    }
    else{
        echo "You cannot upload files of this type!";
    }
}