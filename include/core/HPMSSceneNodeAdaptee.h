/*!
 * File HPMSSceneNodeAdaptee.h
 */


#pragma once

#include <api/HPMSSceneNodeAdapter.h>
#include <core/HPMSAdapteeCommon.h>
#include <common/HPMSUtils.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <Ogre.h>
#include <core/HPMSOgreContextAdaptee.h>
#include <vector>
#include <map>

namespace hpms
{
    class SceneNodeAdaptee : public SceneNodeAdapter, public AdapteeCommon
    {
    private:
        Ogre::SceneNode* ogreNode;
        SceneNodeAdapter* parent;

    public:
        SceneNodeAdaptee(hpms::OgreContextAdaptee* ctx, const std::string& name);

        SceneNodeAdaptee(Ogre::SceneNode* ogreSceneNode, const std::string& name, SceneNodeAdapter* parent);

        virtual ~SceneNodeAdaptee();

        std::string GetName() override;

        void SetPosition(const glm::vec3& position) override;

        glm::vec3 GetPosition() override;

        void SetRotation(const glm::quat& rotation) override;

        glm::quat GetRotation() override;

        void SetScale(const glm::vec3& scale) override;

        glm::vec3 GetScale() override;

        void SetVisible(bool visible) override;

        bool IsVisible() override;

        virtual SceneNodeAdapter* CreateChild(const std::string& name) override;

        virtual void AttachObject(ActorAdapter* actor) override;

        virtual SceneNodeAdapter* RemoveChild(const std::string& name) override;

        virtual SceneNodeAdapter* GetParent() override;

        inline Ogre::SceneNode* GetOgreNode() const
        {
            return ogreNode;
        }
    };
}


DYNALO_EXPORT hpms::SceneNodeAdapter* DYNALO_CALL CreateSceneNode(hpms::ContextAdapter* ctx, const std::string& name);

DYNALO_EXPORT void DYNALO_CALL DestroySceneNode(hpms::SceneNodeAdapter* sceneNode);