DROP TABLE tblProductLab9;
DROP TABLE tblVendorLab9;

CREATE TABLE tblVendorLab9
(
VendorID Number(38) Primary Key,
VendorName VARCHAR2(35) NOT NULL,
VendorContact VARCHAR2(30),
VendorContactPhone VARCHAR2(14)
)
;

CREATE TABLE tblProductLab9
(
ProductID Number(38) Primary Key,
VendorID Number(38),
ProductDesc VARCHAR2(30) NOT NULL UNIQUE,
ProductCost Number(6,2) CHECK(ProductCost >0),
ProductSell Number(6,2),
Constraint SellGreaterThanCost CHECK(ProductSell >= ProductCost),
CONSTRAINT fk_tblProduct_VendorID FOREIGN KEY (VendorID) REFERENCES tblVendorLab9(VendorID)
)
;

-- Question 1 --

CREATE SEQUENCE seq_ProductID_PK
START WITH 1
INCREMENT BY 1
NOMAXVALUE
NOCACHE;

-- Question 2 --

INSERT INTO tblVendorLab9
(VendorID, VendorName, VendorContact, VendorContactPhone)
VALUES
(seq_ProductID_PK.NEXTVAL, 'Acme Corp.', 'Bob Smith', '416-555-9087');

INSERT INTO tblVendorLab9
(VendorID, VendorName, VendorContact, VendorContactPhone)
VALUES
(seq_ProductID_PK.NEXTVAL, 'Hewlett Packard', '', '416-555-3234');

-- Question 3 --

INSERT INTO tblProductLab9 
(ProductID, VendorID, ProductDesc, ProductCost, ProductSell)
VALUES
(seq_ProductID_PK.NEXTVAL, 1, 'Dell Mouse', 25.00, 50.00);

INSERT INTO tblProductLab9 
(ProductID, VendorID, ProductDesc, ProductCost, ProductSell)
VALUES
(seq_ProductID_PK.NEXTVAL, 2, 'HP Pavilion', 230.00, 670.00);

INSERT INTO tblProductLab9 
(ProductID, VendorID, ProductDesc, ProductCost, ProductSell)
VALUES
(seq_ProductID_PK.NEXTVAL, 1, 'Acer HD Monitor', 55.00, 128.00);

-- Question 4 --

UPDATE tblProductLab9
SET ProductCost = 195.00,
    ProductSell = 650.00
WHERE ProductID = 4;

-- Question 5 --

SELECT last_number FROM user_sequences WHERE sequence_name='SEQ_PRODUCTID_PK';
ALTER SEQUENCE seq_ProductID_PK INCREMENT BY -5;
SELECT seq_ProductID_PK.NEXTVAL FROM dual;
ALTER SEQUENCE seq_ProductID_PK INCREMENT BY 1;
SELECT last_number FROM user_sequences WHERE sequence_name='SEQ_PRODUCTID_PK';
