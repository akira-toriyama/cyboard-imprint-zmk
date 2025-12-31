import * as hoipoiCapsule from "https://deno.land/x/hoipoi_capsule@v3.0.2/mod.ts";

const o = await hoipoiCapsule.preset.fillInCommitMessage.gitmojiStyle
  .initialize();

const gitmojiQ = () =>
  hoipoiCapsule.userInterface.prompt.Select.prompt({
    message: "Select gitmoji.",
    search: true,
    options: o.gitmojis,
  });

const commitMessageTemplate = `{{gitmoji}}: {{summary}}

{{body}}`;

hoipoiCapsule.useCase.fillInCommitMessage.run({
  commitMessageTemplate,
  questionList: [
    {
      target: "gitmoji",
      q: gitmojiQ,
    },
    {
      target: "summary",
      q: hoipoiCapsule.preset.fillInCommitMessage.gitmojiStyle.qMap.summary,
    },
    {
      target: "body",
      q: hoipoiCapsule.preset.fillInCommitMessage.gitmojiStyle.qMap.bodyQ,
      fixCommitMessage: hoipoiCapsule.preset.fillInCommitMessage.gitmojiStyle
        .fixCommitMessageMap.body,
    },
  ],
});