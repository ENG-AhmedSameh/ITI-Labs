<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version="1.0">

    <xsl:template match="/">
        <html>
            <head>
                <title>CD collection</title>
                <style>
                    table, th, td {
                    border: 1px solid black;
                    border-collapse: collapse;
                    }
                </style>
            </head>

            <body>
                <h2>CD collection</h2>
                <table border="1">
                    <tr bgcolor="#9acd32">
                        <th>title</th>
                        <th>price</th>
                    </tr>
                    <xsl:for-each select="CATALOG/CD">
                        <xsl:sort select="PRICE"/>
                        <xsl:if test="PRICE &lt; 10">
                            <tr>
                                <td>
                                    <xsl:value-of select="TITLE"/>
                                </td>
                                <td>
                                    <xsl:value-of select="PRICE"/>
                                </td>
                            </tr>
                        </xsl:if>
                    </xsl:for-each>
                </table>
            </body>
        </html>


    </xsl:template>


</xsl:stylesheet>