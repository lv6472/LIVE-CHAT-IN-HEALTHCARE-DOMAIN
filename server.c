CREATE TABLE BB_Manager ( M_id int NOT NULL PRIMARY KEY, mName varchar(100) NOT NULL, m_phNo bigint );
 
INSERT into BB_Manager
VALUES(101,'shivank', 9693959671)
(102,'shwetanshu', 9693959672),
(103,'singh', 9693959673),
(104,'yusuf', 9693959674),
(105,'jackson', 9693959675);
 
INSERT into BB_Manager
VALUES(106,'akhil', 9693959676),
(107,'jojo', 9693959677)
(108,'stella', 9693959678),
(109,'monika', 9693959679),
(110,'himanshi', 9693959680);
select * from BB_Manager;
 
CREATE TABLE Blood_Donor
( bd_ID int NOT NULL PRIMARY KEY,
bd_name varchar(100) NOT NULL,
bd_age varchar(100),
bd_sex varchar(100),
bd_Bgroup varchar(10),
bd_reg_date date
reco_ID int NOT NULL,
City_ID int NOT NULL,
FOREIGN KEY(reco_ID) REFERENCES Recording_Staff(reco_ID)
FOREIGN KEY(City_ID) REFERENCES City(City_ID) );
 
INSERT into Blood_Donor
VALUES(150011,'Mark',25,'M','O+','2015-07-19',101412,1100),
(150012,'Abdul',35,'M','A-','2015-12-24',101412,1100), (150013,'Shivank',22,'M','AB+','2015-08-28',101212,1200), (150014,'shweta',29,'M','B+','2015-12-17',101212,1300),
(150015,'Shyam',42,'M','A+','2016-11-22',101212,1300),
(150016,'Dan',44,'F','AB-','2016-02-06',101212,1200),
(150017,'Mike',33,'M','B-','2016-10-15',101312,1400),
(150018,'Elisa',31,'F','O+','2016-01-04',101312,1200),
(150019,'Carrol',24,'F','AB+','2016-09-10',101312,1500),
(150020,'shivansh',29,'M','O-','2016-12-17',101212,1200);
 
 
select * from Blood_Donor;
 
​
CREATE TABLE BloodSpecimen
( specimen_number int NOT NULL,
b_group varchar(10) NOT NULL,
status int,
dfind_ID int NOT NULL,
M_id int NOT NULL,
primary key (specimen_number,b_group),
FOREIGN KEY(M_id) REFERENCES Manager(M_id),
FOREIGN KEY(dfind_ID) REFERENCES DiseaseFinder(dfind_ID)
);
INSERT into BloodSpecimen
VALUES(1001, 'B+', 1,11,101),
(1002, 'O+', 1,12,102),
(1003, 'AB+', 1,11,102),
(1004, 'O-', 1,13,103 ),
(1005, 'A+', 0,14,101),
(1006, 'A-', 1,13,104),
(1007, 'AB-', 1,15,104),
(1008, 'AB-', 0,11,105),
(1009, 'B+', 1,13,105),
(1010, 'O+', 0,12,105),
(1011, 'O+', 1,13,103),
(1012, 'O-', 1,14,102),
(1013, 'B-', 1,14,102),
(1014, 'AB+', 0,15,101);
Select * from BloodSpecimen;
 
CREATE TABLE City
( City_ID int NOT NULL PRIMARY KEY,
City_name varchar(100) NOT NULL
);
INSERT into City
VALUES(1100,'Dallas'),
(1200,'Austin'),
(1300,'Irving'),
(1400,'Houston'),
(1500,'Richardson');
INSERT into City
VALUES(1600,'Plano'),
(1700,'Frisco'),
(1800,'Arlington'),
(1900,'San Antonio'),
(2000,'Tyler');
select * from City;
 
CREATE TABLE DiseaseFinder
( dfind_ID int NOT NULL PRIMARY KEY,
dfind_name varchar(100) NOT NULL,
dfind_PhNo bigint
);
INSERT into DiseaseFinder
VALUES(11,'Peter',9693959681),
(12,'Park',9693959682),
(13,'Jerry',9693959683),
(14,'shivam',9693959672),
(15,'Monika',9693959679);
INSERT into DiseaseFinder
VALUES(16,'Ram',9693959684),
(17,'Swathi',9693959685),
(18,'Gautham',9693959686),
(19,'Ashwin',9693959687),
(20,'Yash',9693959688);
select * from DiseaseFinder;
 
 
CREATE TABLE Hospital_Info_1
( hosp_ID int NOT NULL,
hosp_name varchar(100) NOT NULL,
City_ID int NOT NULL,
M_id int NOT NULL,
primary key(hosp_ID),
FOREIGN KEY(M_id) REFERENCES Manager(M_id),
FOREIGN KEY(City_ID) REFERENCES City(City_ID)
);
INSERT into Hospital_Info_1
VALUES(1,'MayoClinic',1100,101),
(2,'CleavelandClinic',1200,103),
(3,'NYU',1300,103);
INSERT into Hospital_Info_1
VALUES(4,'Baylor',1400,104),
(5,'Charlton',1800,103),
(6,'Greenoaks',1300,106),
(7,'Forestpark',1300,102),
(8,'Parkland',1200,106),
(9,'Pinecreek',1500,109),
(10,'WalnutHill',1700,105);
select * from Hospital_Info_1;
 
CREATE TABLE Hospital_Info_2
( hosp_ID int NOT NULL,
hosp_name varchar(100) NOT NULL,
hosp_needed_Bgrp varchar(10),
hosp_needed_qnty int,
primary key(hosp_ID,hosp_needed_Bgrp)
);
INSERT into Hospital_Info_2
VALUES(1,'MayoClinic','A+',20),
(1,'MayoClinic','A-',0),
(1,'MayoClinic','AB+',40),
(1,'MayoClinic','AB-',10),
(1,'MayoClinic','B-',20);
INSERT into Hospital_Info_2
VALUES(2,'CleavelandClinic','A+',40),
(2,'CleavelandClinic','AB+',20),
(2,'CleavelandClinic','A-',10),
(2,'CleavelandClinic','B-',30),
(2,'CleavelandClinic','B+',0),
(2,'CleavelandClinic','AB-',10);
INSERT into Hospital_Info_2
VALUES(3,'NYU','A+',0),
(3,'NYU','AB+',0),
(3,'NYU','A-',0),
(3,'NYU','B-',20),
7
0(3,'NYU','B+',10),
(3,'NYU','AB-',0);
INSERT into Hospital_Info_2
VALUES(4,'Baylor','A+',10),
(4,'Baylor','A-',40),
(7,'Forestpark','B-',40),
(8,'Parkland','B+',10),
(9,'Pinecreek','AB-',20);
select * from Hospital_Info_2;
 
CREATE TABLE Recipient
( reci_ID int NOT NULL PRIMARY kEY,
reci_name varchar(100) NOT NULL,
reci_age varchar(10),
reci_Brgp varchar(100),
reci_Bqnty float,
reco_ID int NOT NULL,
City_ID int NOT NULL,
M_id int NOT NULL,
FOREIGN KEY(M_id) REFERENCES Manager(M_id),
FOREIGN KEY(City_ID) REFERENCES City(City_ID)
);
Alter table Recipient
ADD reci_sex varchar(100);
Alter table Recipient
ADD reci_reg_date date;
INSERT into Recipient
VALUES(10001,'Peter',25,'B+',1.5,101212,1100,101,'M','2015-12-17'),
(10002,'shivank',60,'A+',1,101312,1100,102,'M','2015-12-16'),
(10003,'akhil',35,'AB+',0.5,101312,1200,102,'M','2015-10-17'),
(10004,'Parker',66,'B+',1,101212,1300,104,'M','2016-11-17'),
(10005,'jojo',53,'B-',1,101412,1400,105,'M','2015-04-17'),
(10006,'Preetham',45,'O+',1.5,101512,1500,105,'M','2015-12-17'),
(10007,'Swetha',22,'AB-',1,101212,1500,101,'F','2015-05-17');
INSERT into Recipient
VALUES(10008,'Swathi',25,'B+',2,101412,1300,103,'F','2015-12-14'),
(10009,'Lance',30,'A+',1.5,101312,1100,104,'M','2015-02-16'),
(10010,'Marsh',25,'AB+',3.5,101212,1200,107,'M','2016-10-17');
select * from Recipient;
 
CREATE TABLE Recording_Staff
( reco_ID int NOT NULL PRIMARY KEY,
reco_Name varchar(100) NOT NULL,
reco_phNo bigint
);
INSERT into Recording_Staff
VALUES(101012,'Lekha',4044846553),
(101112,'shivam',4045856553),
(101212,'Walcot',4045806553),
(101312,'jackson',4045806553),
(101412,'Silva',4045806553),
(101512,'Adrian',4045806553),
(101612,'shivam',4045806553);
INSERT into Recording_Staff
VALUES(101712,'shyam',4045816553),
(101812,'Jerry',4045826553),
(101912,'Tim',4045836553);
select * from Recording_Staff;
 
Used to set the connections of each page.
<?xml version="1.0"?>
<!--
   Note: As an alternative to hand editing this file you can use the
   web admin tool to configure settings for your application. Use
   the Website->Asp.Net Configuration option in Visual Studio.
   A full list of settings and comments can be found in
   machine.config.comments usually located in
   \Windows\Microsoft.Net\Framework\v2.x\Config
-->
<configuration>
​<appSettings>
​​<add key="ConnStr" value="data source=RAMYA-2DCA5B123;database=BloodBequeathFederalAgent;integrated security=sspi"/>
​</appSettings>
​<connectionStrings>
 <add name="BloodDonationAgentConnectionString" connectionString="Data Source=RAMYA-2DCA5B123;Initial Catalog=BloodDonationAgent;integrated security=sspi"
  providerName="System.Data.SqlClient" />
</connectionStrings>
​<system.web>
​​<!--
           Set compilation debug="true" to insert debugging
           symbols into the compiled page. Because this
           affects performance, set this value to true only
           during development.
       -->
​​<compilation debug="true">
​​​<assemblies>
​​​​<add assembly="System.Design, Version=2.0.0.0, Culture=neutral, PublicKeyToken=B03F5F7F11D50A3A"/>
​​​​<add assembly="System.Web.Extensions, Version=1.0.61025.0, Culture=neutral, PublicKeyToken=31BF3856AD364E35"/>
​​​​<add assembly="System.Web.Extensions.Design, Version=1.0.61025.0, Culture=neutral, PublicKeyToken=31BF3856AD364E35"/>
​​​​<add assembly="System.Windows.Forms, Version=2.0.0.0, Culture=neutral, PublicKeyToken=B77A5C561934E089"/></assemblies></compilation>
​​<!--
           The <authentication> section enables configuration
           of the security authentication mode used by
           ASP.NET to identify an incoming user.
       -->
​​<authentication mode="Windows"/>
​​<!--
           The <customErrors> section enables configuration
           of what to do if/when an unhandled error occurs
           during the execution of a request. Specifically,
           it enables developers to configure html error pages
           to be displayed in place of a error stack trace.
 
       <customErrors mode="RemoteOnly" defaultRedirect="GenericErrorPage.htm">
           <error statusCode="403" redirect="NoAccess.htm" />
           <error statusCode="404" redirect="FileNotFound.htm" />
       </customErrors>
       -->
​</system.web>
</configuration>
 
User Login Form
using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
public partial class Login : System.Web.UI.Page
{
   CheckUser user = new CheckUser();
   UserAccountBusinessLayer account = new UserAccountBusinessLayer();
   OrganizationAccountBusinessLayer org = new OrganizationAccountBusinessLayer();
   protected void Page_Load(object sender, EventArgs e)
   {
       txtUsername.Focus();
   }
 
   protected void btnLogin_Click(object sender, EventArgs e)
   {
       try
       {
           user.Username = txtUsername.Text;
           user.Password = txtPassword.Text;
           //Check User
           
           if (user.GetUser() == true)
           {
               account.Username = txtUsername.Text;
               DataSet ds = new DataSet();
               ds = account.GetAccountId();
               string AcId = ds.Tables[0].Rows[0][0].ToString();
               Session["username"] = txtUsername.Text;
               Session["Acid"] = AcId;
               DataSet ds1 = new DataSet();
               account.Accountid =int.Parse(AcId);
               ds1 = account.GetAddressId();
               Session["addid"] = ds1.Tables[0].Rows[0][0].ToString();
               Response.Redirect("~/Donor/DonorHome.aspx");
           }
           else
               Image2.Visible = true;
           lblMsg.Text = "Your Login Attempt Is Failed Plz try Again....!";
           txtPassword.Text = "";
           txtUsername.Focus();
           //Checking Organization
           if (user.GetOrganization() == true)
           {
               account.Username = txtUsername.Text;
               DataSet ds = new DataSet();
               ds = account.GetAccountId();
               string AcId = ds.Tables[0].Rows[0][0].ToString();
               Session["username"] = txtUsername.Text;
               Session["Acid"] = AcId;
               DataSet ds1 = new DataSet();
               org.Orgid =int.Parse(AcId);
               ds1 = org.GetOrgAddressId();
               Session["addid"]=ds1.Tables[0].Rows[0][0].ToString();
               Response.Redirect("~/Organization/OrganizationHome.aspx");
           }
           else
               Image2.Visible = true;
           lblMsg.Text = "Your Login Atempt Is Failed Plz try Again....!";
           txtPassword.Text = "";
           txtUsername.Focus();
           //Employee Checking
           if (user.CheckEmployee() == true)
           {
               account.Username = txtUsername.Text;
               DataSet ds = new DataSet();
               ds = account.GetAccountId();
               string AcId = ds.Tables[0].Rows[0][0].ToString();
               Session["username"] = txtUsername.Text;
               Session["Acid"] = AcId;
               Response.Redirect("~/CallCenter/CallCenterHome.aspx");
           }