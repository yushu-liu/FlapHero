#pragma once
#include <flapGame/Core.h>
#include <flapGame/GLHelpers.h>
#include <flapGame/Text.h>
#include <flapGame/Shaders.h>
#include <flapGame/VertexFormats.h>
#include <soloud_wav.h>

namespace flap {

struct Bone {
    String name;
    s32 parentIdx = -1;
    Float4x4 boneToParent = Float4x4::identity();
};

struct PoseBone {
    u32 boneIndex = 0;
    float zAngle = 0;
};

struct BirdAnimData {
    Array<Bone> birdSkel;
    Array<PoseBone> loWingPose;
    Array<PoseBone> hiWingPose;
    Array<PoseBone> eyePoses[4];
};

struct FallAnimFrame {
    float verticalDrop = 0;
    float recoilDistance = 0;
    float rotationAngle = 0;
};

struct DrawGroup {
    struct Instance {
        Float4x4 itemToGroup = Float4x4::identity();
        const DrawMesh* drawMesh = nullptr;
    };

    Array<Instance> instances;
    Float3 groupRelWorld = {0, 0, 0};
    float groupScale = 0.f;
};

struct Assets {
    String rootPath;

    struct BirdParts {
        Array<Owned<DrawMesh>> beak;
        Array<Owned<DrawMesh>> skin;
        Array<Owned<DrawMesh>> wings;
        Array<Owned<DrawMesh>> belly;
        Array<Owned<DrawMesh>> eyeWhite;
        Array<Owned<DrawMesh>> pupil;
    };
    BirdParts bird;
    Array<Owned<DrawMesh>> floor;
    Array<Owned<DrawMesh>> floorStripe;
    Array<Owned<DrawMesh>> dirt;
    Array<Owned<DrawMesh>> pipe;
    Array<Owned<DrawMesh>> shrub;
    Array<Owned<DrawMesh>> shrub2;
    Array<Owned<DrawMesh>> city;
    Array<Owned<DrawMesh>> cloud;
    Array<Owned<DrawMesh>> title;
    Array<Owned<DrawMesh>> titleSideBlue;
    Array<Owned<DrawMesh>> titleSideRed;
    Array<Owned<DrawMesh>> outline;
    Array<Owned<DrawMesh>> blackOutline;
    Array<Owned<DrawMesh>> star;
    Array<Owned<DrawMesh>> rays;
    DrawGroup shrubGroup;
    DrawGroup cloudGroup;
    DrawGroup cityGroup;

    BirdAnimData bad;
    Array<FallAnimFrame> fallAnim;

    Texture flashTexture;
    Texture speedLimitTexture;
    Texture waveTexture;
    Texture hypnoPaletteTexture;
    Texture cloudTexture;
    Texture windowTexture;
    Texture stripeTexture;
    Texture shrubTexture;
    Texture shrub2Texture;
    Texture pipeEnvTexture;
    Texture eyeWhiteTexture;
    Texture gradientTexture;
    Texture starTexture;
    Texture puffNormalTexture;

    Owned<SDFCommon> sdfCommon;
    Owned<SDFOutline> sdfOutline;
    Owned<SDFFont> sdfFont;

    Owned<MaterialShader> matShader;
    Owned<TexturedMaterialShader> texMatShader;
    Owned<UberShader> duotoneShader;
    Owned<PipeShader> pipeShader;
    Owned<UberShader> skinnedShader;
    Owned<FlatShader> flatShader;
    Owned<StarShader> starShader;
    Owned<RayShader> rayShader;
    Owned<FlashShader> flashShader;
    Owned<TexturedShader> texturedShader;
    Owned<HypnoShader> hypnoShader;
    Owned<CopyShader> copyShader;
    Owned<GradientShader> gradientShader;
    Owned<PuffShader> puffShader;

    // Sounds
    SoLoud::Wav titleMusic;
    SoLoud::Wav transitionSound;
    SoLoud::Wav swipeSound;
    FixedArray<SoLoud::Wav, 4> passNotes;
    SoLoud::Wav finalScoreSound;
    SoLoud::Wav playerHitSound;
    FixedArray<SoLoud::Wav, 2> flapSounds;

    static Owned<Assets> instance;

    static void load(StringView assetsPath);
};

} // namespace flap
