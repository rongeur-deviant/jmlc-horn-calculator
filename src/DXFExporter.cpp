#include "DXFExporter.h"
#include "JMLCHorn.h"
#include "Units.h"
#include <fstream>
#include <iomanip>

namespace DXFExporter {

void exportProfileDXF(
    const std::vector<ProfilePoint>& profile,
    const std::string& filename,
    UnitSystem units
) {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    double scale = (units == UnitSystem::MILLIMETERS) ? 1000.0 : 1.0;

    file << std::fixed << std::setprecision(6);

    // HEADER
    file << "0\nSECTION\n2\nHEADER\n0\nENDSEC\n";

    // TABLES
    file << "0\nSECTION\n2\nTABLES\n";
    file << "0\nTABLE\n2\nLAYER\n70\n1\n";
    file << "0\nLAYER\n2\n0\n70\n0\n62\n7\n6\nCONTINUOUS\n";
    file << "0\nENDTAB\n";
    file << "0\nENDSEC\n";

    // ENTITIES
    file << "0\nSECTION\n2\nENTITIES\n";
    file << "0\nPOLYLINE\n";
    file << "8\n0\n";
    file << "66\n1\n";
    file << "70\n0\n";

    for (const auto& p : profile) {
        file << "0\nVERTEX\n";
        file << "8\n0\n";
        file << "10\n" << p.x * scale << "\n";
        file << "20\n" << p.y * scale << "\n";
        file << "30\n0.0\n";
    }

    file << "0\nSEQEND\n";
    file << "0\nENDSEC\n";
    file << "0\nEOF\n";

    file.close();
}

}