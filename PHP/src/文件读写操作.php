<?PHP
  echo '留言本发布功能', '<br \>';

  print_r($_POST);
  echo '<br \>';
  
  echo '留言标题为:', $_POST['title'], '<br \>';
  echo '留言内容为:', $_POST['content'], '<br \>';

  $szMsg = $_POST['title'].",".$_POST['content']."\r\n";

  $fpFile = fopen('./MSG.txt', 'r');

  fwrite($fpFile, $szMsg);

  rewind($fpFile);
  print_r(fgetcsv($fpFile));

  fclose($fpFile);

?>