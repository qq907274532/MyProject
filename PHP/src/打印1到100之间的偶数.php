<?php
  echo '��ӡ1~100֮���ż��', '<br \>';
  $nNum = 1;
  $nCount = 0;
  while($nNum <= 100)
  {
    if(!($nNum % 2))
    {
      if($nNum < 10)
      {
        echo '0', $nNum, ' ';
        $nNum++;
        $nCount++;
      }
      else
      {
        echo $nNum, ' ';
        $nNum++;
        $nCount++;
      }
    }
    else
    {
      $nNum++;
    }
    if(!($nCount % 5))
      echo '<br \>';
  }
?>