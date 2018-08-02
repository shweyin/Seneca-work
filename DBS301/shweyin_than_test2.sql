CREATE TABLE InvoiceDetail(
    InvoiceID NUMBER(38), 
    ProductID NUMBER(38),
    Quantity NUMBER(5) DEFAULT 0 NOT NULL, 
    UnitPrice NUMBER(7,2) NOT NULL, 
    Notes VARCHAR2(50),
    CONSTRAINT check_invoiceid CHECK (InvoiceID >= 1),
    CONSTRAINT check_productid CHECK (ProductID >= 1),
    CONSTRAINT check_quantity CHECK (Quantity >= 0)
);

ALTER TABLE InvoiceDetail ADD
CONSTRAINT invoiceDetail_pk PRIMARY KEY (InvoiceID, ProductID);

ALTER TABLE InvoiceDetail ADD
CONSTRAINT FOREIGN KEY(InvoiceID)
REFERENCES Invoice(InvoiceID);

ALTER TABLE InvoiceDetail ADD
CONSTRAINT FOREIGN KEY(ProductID)
REFERENCES Product(ProductID);

INSERT INTO InvoiceDetail (InvoiceID, ProductID, Quantity, UnitPrice, Notes)
VALUES (1, 1, 3, 5.26, '');

INSERT ALL
    INTO InvoiceDetail (InvoiceID, ProductID, Quantity, UnitPrice, Notes) 
        VALUES(1, 4, 2, 12.05, 'Special pricing for this order')
    INTO InvoiceDetail (InvoiceID, ProductID, Quantity, UnitPrice, Notes)
        VALUES(2, 1, 2, 3.95, '')
SELECT * FROM dual;

UPDATE InvoiceDetail
SET UnitPrice = 4.95
WHERE InvoiceID = 2 AND ProductID = 1;

UPDATE InvoiceDetail
SET UnitPrice = UnitPrice * 1.30;

ALTER TABLE InvoiceDetail
DROP COLUMN Notes;

CREATE SEQUENCE test2_sequence
START WITH 5
INCREMENT BY 1
MAXVALUE 900
NOCACHE;