<?PHP
  echo '���Ա���������', '<br \>';

  print_r($_POST);
  echo '<br \>';
  
  echo '���Ա���Ϊ:', $_POST['title'], '<br \>';
  echo '��������Ϊ:', $_POST['content'], '<br \>';

  $szMsg = $_POST['title'].",".$_POST['content']."\r\n";

  $fpFile = fopen('./MSG.txt', 'r');

  fwrite($fpFile, $szMsg);

  rewind($fpFile);
  print_r(fgetcsv($fpFile));

  fclose($fpFile);

?>