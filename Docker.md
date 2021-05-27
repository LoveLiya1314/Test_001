deban换源
sudo sed -i 's/deb.debian.org/mirrors.ustc.edu.cn/g' /etc/apt/sources.list

mysql的一些配置：
	docker run --name dockermysql  -p 3306:3306 -e MYSQL_ROOT_PASSWORD=mysqlpassword -d mysql
		use mysql;
		grant all privileges on *.* to 'root'@'%';
		select Host,User,plugin from user;
		alter user 'root'@'%' identified with mysql_native_password by 'yourPassword';
		flush privileges;

nginx的default.conf配置：

server {
        listen       80 default_server;
        listen       [::]:80 default_server;
        
        # 默认网站根目录（www目录）
        root         /var/www/;
        # Load configuration files for the default server block.
        include /etc/nginx/default.d/*.conf;
        location / {
            # 这里改动了 定义首页索引文件的名称
            index index.php index.html index.htm;
        }
        error_page 404 /404.html;
            location = /40x.html {
        }
        error_page 500 502 503 504 /50x.html;
            location = /50x.html {
        }
        # 这里新加的
        # PHP 脚本请求全部转发到 FastCGI处理. 使用FastCGI协议默认配置.
        # Fastcgi服务器和程序(PHP,Python)沟通的协议.
        location ~ \.php$ {
            # 设置监听端口
            fastcgi_pass   php-Zero:9000;
            # 设置nginx的默认首页文件(上面已经设置过了，可以删除)
            fastcgi_index  index.php;
            # 设置脚本文件请求的路径
            fastcgi_param  SCRIPT_FILENAME  $document_root$fastcgi_script_name;
            # 引入fastcgi的配置文件
            include        fastcgi_params;
        }
    }

Redis的一些配置：
		docker run --name Redis -p 6379:6379 -d redis

PHP：
	docker run -d -p 9000:9000 --name PHP_Zero -v E:\Docker\www\web:/var/www/html --link dockermysql:dockermysql --link Redis:Redis --privileged=true php

	docker run -d -p 9000:9000 --name PHP_Zero -v E:\Docker\www\web:/var/www/html --link dockermysql:dockermysql --link Redis:Redis  php

nginx:
	docker run --name lnmp  -d -p 80:80 -p 443:443 -v E:\Docker\www\web:/var/www -v E:\Docker\www\config:/etc/nginx/conf.d  --link PHP_Zero:php  nginx

