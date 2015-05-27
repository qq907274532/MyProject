<?php
  echo '打印1~100之类的偶数', '<br \>';
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