#include "testfileutils.h"

#include <QString>
#include <QtTest>

#include "../../src/helpers/fs/fileutils.h"

void testFileUtils::shouldGetFileName() {
    QString path = "/home/user/documents/notes.txt";
    QCOMPARE(FileUtils::getFileName(path), QString("notes.txt"));
}


QTEST_MAIN(testFileUtils)