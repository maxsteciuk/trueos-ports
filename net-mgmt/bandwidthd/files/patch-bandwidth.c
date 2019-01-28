--- bandwidthd.c.orig	2005-01-11 16:27:26.000000000 -0500
+++ bandwidthd.c	2019-01-13 21:24:53.931929000 -0500
@@ -258,19 +258,19 @@
 	if (stat("./etc/bandwidthd.conf", &StatBuf))
 		{
 		chdir(INSTALL_DIR);
-		if (stat("./etc/bandwidthd.conf", &StatBuf))
+		if (stat("./bandwidthd.conf", &StatBuf))
 			{
-			printf("Cannot find ./etc/bandwidthd.conf or %s/etc/bandwidthd.conf\n", INSTALL_DIR);
-			syslog(LOG_ERR, "Cannot find ./etc/bandwidthd.conf or %s/etc/bandwidthd.conf", INSTALL_DIR);
+			printf("Cannot find ./etc/bandwidthd.conf or %s/bandwidthd.conf\n", INSTALL_DIR);
+			syslog(LOG_ERR, "Cannot find ./etc/bandwidthd.conf or %s/bandwidthd.conf", INSTALL_DIR);
 			exit(1);
 			}
 		}
 
-	bdconfig_in = fopen("./etc/bandwidthd.conf", "rt");
+	bdconfig_in = fopen("./bandwidthd.conf", "rt");
 	if (!bdconfig_in)
 		{
 		syslog(LOG_ERR, "Cannot open bandwidthd.conf");
-		printf("Cannot open ./etc/bandwidthd.conf\n");
+		printf("Cannot open ./bandwidthd.conf\n");
 		exit(1);
 		}
 	bdconfig_parse();
