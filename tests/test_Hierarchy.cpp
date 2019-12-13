#include "../Hierarchy.h"
#include "../Bone.h"

int main(int argc, char** argv) {
	Hierarchy<HierarchyItem<Bone*>> bones;
	// XMLItem *Model=new XMLItem("Model");
// XMLItem *Transform=new XMLItem("Transform");
// 	XMLItem *Position=new XMLItem("Position");
// 		XMLItem *Vec3=new XMLItem("Vec3");
// 	XMLItem *Rotation=new XMLItem("Rotation");
// 		XMLItem *Vec31=new XMLItem("Vec31");		
// 	XMLItem *Scale=new XMLItem("Scale");
// 		XMLItem *Vec32= new XMLItem("Vec32");
// XMLItem *Texture= new XMLItem("Texture");



	// HierarchyItem<Bone*> HierarchyItemBone1(new Bone("Bone1"));
	// HierarchyItem<Bone*> HierarchyItemBone2(new Bone("Bone2"));
	// HierarchyItem<Bone*> HierarchyitemBone3(new Bone("Bone3"));

	// HierarchyItemBone1.Child(&HierarchyItemBone2)->Child(&HierarchyitemBone3);
	// HierarchyItemBone1.Serialize();

	// Hierarchy<HierarchyItem<Bone*>> hierarchyOfBones;
	// hierarchyOfBones.head=&HierarchyItemBone1;
	// hierarchyOfBones.parseTree(&HierarchyItemBone1);



	Bone* Bone1 = new Bone("Bone1");
	Bone* Bone2 = new Bone("Bone2");
	Bone* Bone3 = new Bone("Bone3");
	Bone* Bone4 = new Bone("Bone4");
	
	Hierarchy<Bone*> hierarchyOfBones(Bone1);
	hierarchyOfBones.head->Child(Bone2)->Child(Bone3);
	hierarchyOfBones.AddChild(Bone2,Bone4);
/*	
	Bone1
		Bone2
			Bone4
		Bone3
*/
	// hierarchyOfBones.head=&HierarchyItemBone1;
	hierarchyOfBones.parseTree();
	


	return 0;
}
