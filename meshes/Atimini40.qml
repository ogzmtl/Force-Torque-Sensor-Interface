import QtQuick
import QtQuick3D

Node {
    id: node

    // Resources
    PrincipledMaterial {
        id: defaultMaterial_material
        baseColor: "#ff999999"
        roughness: 1
        indexOfRefraction: 1
    }

    // Nodes:
    Node {
        id: atimini40_obj
        Model {
            id: obj1
            source: "meshes/obj1.mesh"
            materials: defaultMaterial_material
        }
    }

    // Animations:
}
