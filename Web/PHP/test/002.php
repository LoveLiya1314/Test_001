
<?php
$ip = @file_get_contents("http://ip.taobao.com/service/getIpInfo.php?ip=".$_GET["223.99.9.137"]);
$ip = json_decode($ip,true);
?>
